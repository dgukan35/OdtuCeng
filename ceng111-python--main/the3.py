import math
epsilon = math.exp(-6)
def relu(x):
    resultrelu = []
    for i in x:
        maksimum = max(0, i)
        resultrelu.append(maksimum)
    return resultrelu
def sigmoid(x):
    resultsigmoid = []
    for i in x:
        if i <= -700:
            resultsigmoid.append(0)
        elif i > -700:
            if i < 700:
                resultsigmoid.append(1/(1 + math.exp(-i)))
            else:
                resultsigmoid.append(1)
    return resultsigmoid
def linear(n, x):
    result = []
    for i in range(len(n[1])):
        value = 0
        for j in range(len(x)):
            value += n[1][i][j] * x[j]
        result.append(value)
    return result
def forward_pass(Network, X):
    for i in Network:
        if type(i) != str:
                X = linear(i, X)
        else:
            if i.count("relu",0,4) == 1:
                X = relu(X)
            elif i.count("sigmoid",0,7) == 1:
                X = sigmoid(X)
    return X














