#include <bits/stdc++.h>
using namespace std;
//Feito por João Paulo Vasquez Dias e Pedro Henrique Bouvie Roewer
#define SHELL 1
#define KNUTH 2
#define CIURA 3

const string names[3] = {"SHELL", "KNUTH", "CIURA"};

const long ciura_sequence[17]= {1,4,10,23,57,132,301,701,1577,3548,7983,17961,40412,90927,204585,460316,1035711};

//--------------------------------------------------------------
void print_array(const vector<int> C, int tam){
    for(int i =0; i< tam; i++){
        printf("%d ", C[i]);
    }
}

void shell_sort(vector<int> C, int tam, int type, bool print_iterations)
{
//--------------------------------------------------------------
    if(print_iterations)
        print_array(C, tam), printf("SEQ= %s\n", names[type-1].c_str());

    clock_t start_clock, end_clock;

    long changes = 0;
    int i, j, chave;
    int h = 1, index = 0;

    start_clock = clock();
    while (h < tam)
    {
        switch (type)
        {
        case SHELL:
            h *= 2;
            break;
        case KNUTH:
            h = 3*h+1;
            break;
        case CIURA:
            h = ciura_sequence[++index];
            break;
        }
    }

    while ( h > 1)
    {
        switch (type)
        {
        case SHELL:
            h /= 2;
            break;
        case KNUTH:
            h /= 3;
            break;
        case CIURA:
            h = ciura_sequence[--index];
            break;
        }
        for(i = h; i < tam; i++)
        {
            chave = C[i];
            j = i - h;
            while (j >= 0 && chave < C[j])
            {
                C [j+h] = C[j];
                changes++;
                j -= h;
            }
            C [j+h] = chave;
        }
        if(print_iterations)
            print_array(C, tam), printf("INCR=%d\n", h);
    }
    end_clock = clock();

    if(!print_iterations)
        printf("%s,%d,%f\n", names[type-1].c_str(), tam, (end_clock - start_clock)/(double)CLOCKS_PER_SEC);
}


int main()
{
    int tamanho_vetor;
    vector<int> vetor(1000005, 0);
    while (scanf("%d", &tamanho_vetor) != EOF)

    {
        for (int i=0; i<tamanho_vetor; i++)
            scanf("%d", &vetor[i]);

        shell_sort(vetor, tamanho_vetor, SHELL, false);
        shell_sort(vetor, tamanho_vetor, KNUTH, false);
        shell_sort(vetor, tamanho_vetor, CIURA, false);
    }
}
