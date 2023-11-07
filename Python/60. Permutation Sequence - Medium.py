'''def getPermutaion(n,k):

    def PermutationCreator(number, list_to_permute):
        if stop == k:
            return "".join(permutation)

        if len(list_to_permute) == 1:
            permutation = number + list_to_permute
            stop += 1
        else:
            for i in range(len(list_to_permute)):
                PermutationCreator(number + [list_to_permute[i]], list_to_permute[:i] + list_to_permute[i + 1:])

    stop = 0
    permutation = ''
    permutation_list = [i for i in range(1, n + 1)]
    PermutationCreator([],permutation_list)'''


'''Copied solution from https://leetcode.com/problems/permutation-sequence/discuss/696782/Python3-Solution-Explained-With-a-Tip-For-Faster-Execution-or-Beats-99.8'''

Try to understand this.



print(getPermutaion(3,3))