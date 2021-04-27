class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {\
        int ans=0;
        if(A>=E&&B>=F&&C<=G&&D<=H) ans=abs(E-G)*abs(F-H);
        else if(A<=E&&B<=F&&C>=G&&D>=H) ans=abs(A-C)*abs(B-D);
        else if(A>=G||E>=C||B>=H||D<=F){
            ans=abs(E-G)*abs(F-H)+abs(A-C)*abs(B-D);
        }
        else {
            ans=abs(E-G)*abs(F-H)+abs(A-C)*abs(B-D);
            ans-=abs(max(A,E)-min(C,G))*abs(max(B,F)-min(D,H));
        }
        //if()
        return ans;
    }
};