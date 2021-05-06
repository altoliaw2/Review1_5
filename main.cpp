#include <iostream>
template <class CL1>
int fn_GetMerge(CL1* cp_Ori, CL1* cp_OriCopy, int i_SInd, int i_MInd, int i_EInd){
    int i_Num   = 0;
    int i_I     = i_SInd;
    int i_J     = i_MInd + 1;
    int i_K     = i_SInd;
    for(;(i_I <= i_MInd) && (i_J<= i_EInd);){
        if(cp_Ori[i_I] <= cp_Ori[i_J]){
            cp_OriCopy[i_K++]   = cp_Ori[i_I++];
        }
        else{
            i_Num   += (i_MInd - i_I) + 1;
            cp_OriCopy[i_K++]   = cp_Ori[i_J++];
        }
    }

    for(;i_I <= i_MInd;){
        cp_OriCopy[i_K++]   = cp_Ori[i_I++];
    }

    for(int i_Ct = i_SInd; i_Ct <= i_EInd;  i_Ct++){
        cp_Ori[i_Ct]        = cp_OriCopy[i_Ct];
    }
    return i_Num;
}

template <class CL1>
int fn_GetCount(CL1* cp_Ori, CL1* cp_OriCopy, int i_SInd, int i_EInd){
    int i_Num   = 0;
    if(i_SInd  >= i_EInd){
        return 0;
    }

    int i_MInd  = (i_SInd + i_EInd) / 2;
    i_Num       += fn_GetCount(cp_Ori,  cp_OriCopy, i_SInd, i_MInd);
    i_Num       += fn_GetCount(cp_Ori,  cp_OriCopy, (i_MInd + 1), i_EInd);
    i_Num       += fn_GetMerge<CL1>(cp_Ori, cp_OriCopy, i_SInd, i_MInd, i_EInd);
    return i_Num;
}



int main(){
    int i_Num   = 0;
    std::cin >> i_Num;
    int* ip_Ori     = new int[i_Num];
    int* ip_OriCopy = new int[i_Num];

    for(int i_Ct=0; i_Ct< i_Num; i_Ct++){
        int i_Tmp       = 0;
        std::cin >> i_Tmp;
        ip_Ori[i_Ct]    = i_Tmp;
        ip_OriCopy[i_Ct]= i_Tmp;
    }

    std::cout<< fn_GetCount<int>(ip_Ori, ip_OriCopy, 0, (i_Num - 1)) << "\n";


    delete [] ip_Ori;
    delete [] ip_OriCopy;
    return  0;
}
