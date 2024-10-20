class Solution:
    def parseBoolExpr(self, ex: str) -> bool:
        def find(t: int, f: int, logic: str):
            if (logic == '!') :
                return 't' if f > 0 else 'f'
            elif (logic == '&'):
                return 'f' if f > 0 else 't'
            return 't' if t > 0 else 'f'

        st = []
        for i in ex:
            # print(i)
         
            if (i == ')') :
                # print(i)
                t = 0
                f = 0
                while (st[-1] != '('):
                    top = st[-1]
                    t += (top == 't')
                    f += (top == 'f')
                    st.pop()
                st.pop()
                logic = st[-1]
                st.pop()
                st.append(find(t,f,logic))
            else :
                st.append(i)

        return st[0] == 't'

sol = Solution()

print(f"ans for '&(|(f))' is {sol.parseBoolExpr('&(|(f))')}")