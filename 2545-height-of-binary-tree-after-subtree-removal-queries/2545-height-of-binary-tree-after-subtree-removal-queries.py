# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def treeQueries(self, root: Optional[TreeNode], queries: List[int]) -> List[int]:

        def recur(nn):

            if nn.left:
                ll, la = recur(nn.left)
                if nn.right:
                    rl, ra = recur(nn.right)
                else:
                    la[ll[-1]] = 1  # if ll[-1] is deleted, max hight = 0
                    ll.append(nn.val)
                    return ll, la
            elif nn.right:
                rl, ra = recur(nn.right)
                ra[rl[-1]] = 1  # if rl[-1] is deleted, max hight = 0
                rl.append(nn.val)
                return rl, ra
            else:
                return [nn.val], {}

            if len(ll) >= len(rl):
                la[ll[-1]] = len(rl) + 1
                ll.append(nn.val)
                return ll, la
            else:
                ra[rl[-1]] = len(ll) + 1
                rl.append(nn.val)
                return rl, ra

        longest, alt_d = recur(root)
        ll = len(longest) - 1
        new_alt = 0
        new_alt_d = {}
        for i, x in enumerate(longest[::-1][1:]):
            alt = alt_d[x] + i - 1
            new_alt = max(new_alt, alt)
            new_alt_d[x] = new_alt

        return [ new_alt_d[q] if q in new_alt_d else ll for q in queries ]
        

      