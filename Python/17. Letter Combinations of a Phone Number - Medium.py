import itertools

def letterCombinations(digits):
    my_dict = {'2': ['a','b','c'], '3':['d','e','f'], '4':['g','h','i'],'5':['j','k','l'],'6':['m','n','o'],
               '7':['p','q','r','s'],'8':['w','x','y','z']}
    final = []
    for str in digits:
         final.append(my_dict[str])
    else:
        pass

    return list(itertools.product(*final))
