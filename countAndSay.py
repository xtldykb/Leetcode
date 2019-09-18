def s(n, temp={}):
    if n == 1:
        return '1'
    try:
        return temp[n]
    except KeyError:
        temp[n] = bs(s(n - 1))
        return temp[n]

def bs(str0):
    ls = list(str0)
    ls.append('0')
    ls0 = []
    re = 0
    i = 0
    while i < len(ls) - 1:
        if ls[i] != ls[i + 1]:
            ls0.append(str(i + 1 -re))
            ls0.append(ls[i])
            re = i + 1
        i = i + 1
    s_Out = ''.join(ls0)
    return s_Out

def main():
    print(s(55))


if __name__ == '__main__':
    main()