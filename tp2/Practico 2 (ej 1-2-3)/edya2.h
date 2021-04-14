using namespace std;
//########### Ejercicio 1 #############
void Metodo_at(const string& str){
    unsigned int i;
    for (i=0;i<str.length();i++){
        //cout<<str.at(i)<<"  ";
    }
}
void operador_de_inter(const string& str){
    unsigned int i;
    for(i=0;i<str.length();i++){
        //cout<<str[i]<<"  ";
    }
}
void iterador(const string& str){
    for (auto it=str.begin();it!=str.end();++it){
        //cout<<*it<<"  ";
    }
}
void bucle_rang(const string& str){
     for (char j : str){
        //cout<<j<<"  ";
    }
}
//########### Ejercicio 2 #############
string palindromePyramid(const string& str){
    string ret="";
    int i,j,sav;
    if(str.length()%2!=0){//si el string tiene caracteres pares o impares
        sav=str.length()/2;
        j=1;
    }
    else{
        sav=(str.length()/2)-1;
        j=2;
    }
    for(i=sav;i>=0;i--){//genero el nuevo string
        ret.append(i,' ');
        ret+=str.substr(i,j);
        ret.append(i,' ');
        ret+="\n";
        if(str.substr(i,j)[0]!=str.substr(i,j)[j-1]){//compruebo que lo que copio sea palindromo
            ret="El string no es palindromo";
            i=-1;
        }
        j+=2;
    }
    return ret;
}
//########### Ejercicio 3 #############
string replaceAll(const string& str, const string& from, const string& to){
    string ret="";
    unsigned int i,j;
    j=from.length();
    for(i=0;i<(str.length()-j);i++){
        if (str.substr(i,j)==from){
            ret+=to;
            i+=(j-1);
        }
        else{
            ret+=str.substr(i,1);
        }
    }
    ret+=str.substr(i,j);
    return ret;
}
