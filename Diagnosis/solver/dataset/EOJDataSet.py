import torch
from torch.utils.data.dataset import Dataset
from ..config import config
import json
import numpy as np
import pandas as pd

class EOJDataSet(Dataset):
    def __init__(self, students: dict, exercise_concept: dict, model_concept_path: str, model_exercise_path: str, is_train = False):
        self.is_train = is_train
        self.exercise_concept = exercise_concept

        with open(model_concept_path, 'r') as f:
            self.model_concept: dict = json.load(f)
        with open(model_exercise_path, 'r') as f:
            self.model_exercise: dict = json.load(f)

        if is_train:
            pass
        else:
            self.stu = students
            self.idx = list()   # students' id 10xx5102xxx
            for id, submits in students.items():
                self.idx.append(id)
                
            self.concept = torch.zeros([len(self.model_exercise) + 1, 4])   # 4 is max concepts in one exercise
            for OJ_id, e_id in self.model_exercise.items():
                cons = self.exercise_concept.get(OJ_id, [])
                for i, c in enumerate(cons):
                    self.concept[e_id, i] = self.model_concept.get(c, 0)


    def __len__(self):
        return len(self.idx)
    
    def __getitem__(self, index):
        if self.is_train:
            pass
        else:
            id = self.idx[index]
            submits = list()

            for submit in self.stu[id]:
                if self.model_exercise.get(submit[0], 0) != 0:
                    submits.append(submit)
            submits = submits[-(config.MAX_STEP-1):]

            ques        = torch.zeros(config.MAX_STEP)
            concepts    = torch.zeros([config.MAX_STEP, 4])
            ans       = torch.zeros(config.MAX_STEP)
            score       = torch.zeros(config.MAX_STEP)

            cnt = 0
            for i in range(len(submits)):
                assert(i<config.MAX_STEP-1)
                q = self.model_exercise[submits[i][0]]
                a = submits[cnt][2]

                ques[cnt] = q
                concepts[cnt,:] = self.concept[q,:]
                ans[cnt+1] = a
                score[cnt] = a
                cnt += 1
            return id, ques.long(), concepts.long(), ans.long(), score.long()