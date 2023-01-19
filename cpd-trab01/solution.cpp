#include <bits/stdc++.h>
//feito por joão paulo vasquez dias
using namespace std;

int insertion_sort(string C, int tam)
{
    int changes = 0;
    int i, j;
    char chave;

    for(j=1; j<tam; j++)
    {
        chave = C[j];
        i = j-1;
        while((i>=0) && (C[i]>chave))
        {
            C[i+1] = C[i];
            i--;
            changes++;
        }
        C[i+1] = chave;
    }
    return changes;
}

string chars[110];
vector< pair <int,int> > indexes;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, n, m;
    bool first = true;
    cin>>M;
    while(M--){
        if(first){
            first = false;
        }
        else{
            cout<<endl;
        }
        cin>>n>>m;
        indexes.clear();
        for(int i = 0; i< m; i++){
            cin>>chars[i];
            indexes.push_back( make_pair(insertion_sort(chars[i], n), i));
        }
        sort(indexes.begin(), indexes.end());
        for(int i = 0; i< m; i++){
            cout<<chars[indexes[i].second]<<endl;
        }
    }
}
