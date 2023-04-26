import torch

class config(object):
    device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
    # device = torch.device('cpu')

    # student_n = 143
    exer_n = 141
    knowledge_n = 25
    MAX_STEP = 50

