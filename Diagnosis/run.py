import os
# os.chdir('/mbc/Diagnosis')
# os.environ['CUDA_VISIBLE_DEVICES'] = '7'
import json
import logging
import argparse
from tqdm import tqdm
import torch
from torch.utils.data.dataloader import DataLoader

from solver.config import config
from solver.dataset.EOJDataSet import EOJDataSet
from solver.model.SAINTModel import saint

@torch.no_grad()
def eval(model, dataloader):
    model.eval()
    results = dict()
    for stu_id, ques, concepts, ans, score in tqdm(dataloader):
        ques = ques.to(config.device)                # [batch_size, MAX_STEP]
        concepts = concepts.to(config.device)        # [batch_size, MAX_STEP, 4]
        ans = ans.to(config.device)                  # [batch_size, MAX_STEP]
        # codes = codes.to(C.device)              # [batch_size, MAX_STEP]   list type
        score = score.to(config.device)              # [batch_size, MAX_STEP]

        length = torch.count_nonzero(ques, dim=1).to(config.device)

        result = list()
        for i in range(1, config.exer_n):
            ques[0,length] = i
            pred = model(ques, concepts, ans, score).cpu()
            result.append(float(pred[0,length,0]))

        stu_id = stu_id[0]
        results[stu_id] = result

    return results

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('path', type=str, default=None)
    parser.add_argument('--dir', type=str, default='Dataset/', help='directory of path')
    parser.add_argument('--mode', type=str, default='eval', choices=['eval', 'train'], help='eval or train')
    args = parser.parse_args()
    print(args)
    print("device: ", config.device)

    logging.basicConfig(level=logging.DEBUG, filemode='a', filename='demo.log')
    logging.info(os.getcwd())

    path = args.path
    print('dataset: {}'.format(args.dir + path))
    model_concept_path = "solver/model/model_concept.json"
    model_exercise_path = "solver/model/model_exercise.json"
    is_train = (args.mode == 'train')

    model = saint(dim_model=128,
                num_en=2,
                num_de=2,
                heads_en=8,
                heads_de=8,
                total_ex=config.exer_n,
                total_cat=config.knowledge_n+1, # 0 is no concept
                total_in=2,
                seq_len=config.MAX_STEP,
                dropout=0.3
                ).to(config.device)

    SAINTModel_state_dict = torch.load('solver/model/SAINTModel_state_dict.pth', map_location=config.device)
    model.load_state_dict(SAINTModel_state_dict)

    with open(args.dir + path + "_data.json",'r') as f:
        students: dict = json.load(f)
    with open(args.dir + "exercise_concept.json",'r') as f:
        exercise_concept: dict = json.load(f)
    dataset = EOJDataSet(students, exercise_concept, model_concept_path, model_exercise_path, is_train = is_train)
    dataloader = DataLoader(dataset)

    if is_train:
        pass
    else:
        results = eval(model, dataloader)
        
        with open(path + "_results.json",'w') as f:
            json.dump(results, f)

