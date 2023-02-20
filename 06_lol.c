#include<stdio.h>

void llll(int *nums){
    int size=sizeof(nums)/sizeof(int);
    int pos;
        for(int i=size-1;i>0;i--){
            if(nums[i-1]>nums[i]){
                pos=i;
            }
        }

        for(int i=pos;i<size-1;i++){
            nums[i]=nums[i+1];
        }
}

void display(int *nums){
    int size=sizeof(nums)/sizeof(int);
    for(int i=0;i<size;i++){
        printf("%d ",nums[i]);
    }
}

int main(){
    int arr[]={1,2,10,5,7};
    llll(arr);
    display(arr);
    return 0;
}


=SUM(D22:D41)
=SUM(D43:D62)
=SUM(D64:D83)
=SUM(D85:D104)
=SUM(D106:D125)
=SUM(D127:D146)
=SUM(D148:D167)
=SUM(D169:D188)
=SUM(D190:D209)
=SUM(D211:D230)
=SUM(D232:D251)
=SUM(D253:D272)

=SUMIF(B22:B41,J6,D22:F41)
=SUMIF(B43:B62,J6,D43:F62)
=SUMIF(B64:B83,J6,D64:F83)
=SUMIF(B58:B104,J6,D58:F104)
=SUMIF(B106:B125,J6,D106:F125)
=SUMIF(B127:B146,J6,D127:F146)
=SUMIF(B148:B167,J6,D148:F167)
=SUMIF(B169:B188,J6,D169:F188)
=SUMIF(B190:B209,J6,D190:F209)
=SUMIF(B211:B230,J6,D211:F230)
=SUMIF(B232:B251,J6,D232:F251)
=SUMIF(B253:B272,J6,D253:F272)

=SUMIF(B22:B41,K6,D22:F41)
=SUMIF(B43:B62,K6,D43:F62)
=SUMIF(B64:B83,K6,D64:F83)
=SUMIF(B58:B104,K6,D58:F104)
=SUMIF(B106:B125,K6,D106:F125)
=SUMIF(B127:B146,K6,D127:F146)
=SUMIF(B148:B167,K6,D148:F167)
=SUMIF(B169:B188,K6,D169:F188)
=SUMIF(B190:B209,K6,D190:F209)
=SUMIF(B211:B230,K6,D211:F230)
=SUMIF(B232:B251,K6,D232:F251)
=SUMIF(B253:B272,K6,D253:F272)






