#include <stdio.h>
#define DISTRICTS 3
#define MONTHS 4

void annual_totals(const int rain[DISTRICTS][MONTHS], int totals[]) {
    for(int i=0;i<DISTRICTS;++i) {
        totals[i]=0;
        for(int j=0;j<MONTHS;++j) totals[i]+=rain[i][j];
    }
}
void monthly_averages(const int rain[DISTRICTS][MONTHS], double avg[]) {
    for(int j=0;j<MONTHS;++j) {
        int sum=0;
        for(int i=0;i<DISTRICTS;++i) sum+=rain[i][j];
        avg[j]=(double)sum/DISTRICTS;
    }
}
void wettest(const int rain[DISTRICTS][MONTHS], int *district, int *month, int *value) {
    *district=0; *month=0; *value=rain[0][0];
    for(int i=0;i<DISTRICTS;++i)
        for(int j=0;j<MONTHS;++j)
            if(rain[i][j]>*value) {*value=rain[i][j];*district=i;*month=j;}
}
void deficient(const int totals[], double state_average) {
    printf("Deficient districts (<60%% of state average annual total):");
    for(int i=0;i<DISTRICTS;++i)
        if(totals[i] < 0.60*state_average) printf(" %d",i+1);
    puts("");
}
int main(void) {
    const int rain[DISTRICTS][MONTHS]={{40,60,80,20},{30,50,70,10},{100,120,90,80}};
    int totals[DISTRICTS],d,m,v,sum=0; double avg[MONTHS],state_avg;
    annual_totals(rain,totals); monthly_averages(rain,avg);
    puts("RAINFALL RECORDS (3 x 4 verification sample)");
    for(int i=0;i<DISTRICTS;++i){printf("District %d annual total = %d\n",i+1,totals[i]);sum+=totals[i];}
    for(int j=0;j<MONTHS;++j) printf("Month %d average = %.2f mm\n",j+1,avg[j]);
    wettest(rain,&d,&m,&v);
    printf("Wettest cell = District %d, Month %d, %d mm\n",d+1,m+1,v);
    state_avg=(double)sum/DISTRICTS;
    printf("Average annual rainfall per district = %.2f mm\n",state_avg);
    deficient(totals,state_avg);
    return 0;
}
