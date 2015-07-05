class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int r1 = (C - A) * (D - B);
        int r2 = (G - E) * (H - F);
        
         int r_cover;
         if( E >= C || B >= H || G <= A || F >= D)
            r_cover =  0;
         else{
             int cover_x, cover_y;
             
             if(A < E && E < C){
                 if(G < C)
                    cover_x = G - E;
                 else
                    cover_x = C - E;
             }
             else{
                 if(G > A && G < C)
                    cover_x = G - A;
                 else 
                    cover_x = C - A;
             }
             
             if(F > B && F < D){
                 if(H < D)
                    cover_y = H - F;
                 else
                    cover_y = D - F;
             }
             else{
                 if(H > B && H < D)
                    cover_y = H - B;
                 else
                    cover_y = D - B;
             }
             
             r_cover =  cover_x * cover_y;
         }
         
         return r1 + r2 - r_cover;
    }
};