'''
Extra ./path with path_exercise.csv to path_data.json and path_code.json

Input:
./path : directory of submit code_files, which is download from contest's standings pages and unziped
path_exercise.csv : the first column is contest's exercise id and the second column is OJ exercise id, which can be got from meta -> problem

Output:
path_data.json : a dictionary of students' submits, key is student_id, value is a (n x 3) list, n is length with (OJ_id, code_id, score)
path_code.json : a dictionary of codes, key is code_id, value is code_txt


Example:
python extra_data c609_4_14

path = 'c609_4_14'

--c609_4_14/
----1019xxxxx
------1001_#3000000_Accepted.c
------1002_#4000000_Wrong_anser.c

c609_4_14_exercise.csv:
1001,3
1002,5

you will got ->

c609_4_14_data.json:
{'1019xxxxx' : [['3', '3000000', 1], ['5', '4000000', 0]]}

c609_4_14_code.json:
{'3000000' : "#include......return", '3000000' : "#4000000......return"}
'''
import argparse
import pandas as pd
import json
import os

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('path', type=str, default=None)
    parser.add_argument('--dir', type=str, default='Dataset/', help='directory of path')
    args = parser.parse_args()

    path = args.dir + args.path
    path_exercise = path + '_exercise.csv'
    path_data = path + '_data.json'
    path_code = path + '_code.json'
    print('path: {}'.format(path))

    # load 
    EOJ_id = dict()
    with open(path_exercise, 'r') as file:
        df = pd.read_csv(file)
        for a,b in df.values:
            # print(a,b)
            EOJ_id[str(a)] = str(b)
    print('totoal exercise number in {}: {}'.format(path, len(EOJ_id)))

    student_number = 0
    submit_number = 0
    data = dict()
    code = dict()
    for root, _, files in os.walk(path):
        if len(files) == 0:
            continue
        # print(root)
        student_number += 1
        student_id = os.path.split(root)[-1]
        # print(student_id)

        submits = list()
        for file in files:
            if 'Compilation' not in file:
                ques = file.split('_')[0]
                code_ind = file.split('_')[1][1:]
                score = 'Accepted' in file

                # print(ques, code_ind, score)
                # print(EOJ_id[int(ques)], code_ind, int(score))
                ques = EOJ_id[ques]
                score = int(score)
                
                submit_number += 1
                submits.append([ques, code_ind, score])

                with open(os.path.join(root,file), encoding='utf-8') as f:
                    txt = f.read()
                    # print(txt)
                    code[code_ind] = txt
        submits.sort(key = lambda x:x[1])
        data[student_id] = submits
        # print("{} : {}".format(student_id, len(submits)))
    print('student number: {}'.format(student_number))
    print('submit number: {}'.format(submit_number))
        
    # save file
    with open(path_data,'w') as f:
        json.dump(data, f)
    with open(path_code,'w') as f:
        json.dump(code, f)