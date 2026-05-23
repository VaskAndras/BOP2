#include "String.h"
#include <cstring>
#include <iostream>

using namespace HomeMadeString;
String::String()
{
    elementNum=0;
    pData=NULL;
}

String::~String(){
    free(pData);
    elementNum=0;
}

String::String(const String &theOther){
    elementNum= theOther.elementNum;
    pData=(char*)malloc((elementNum+1)*sizeof(char));
    for(int i=0; i<elementNum; i++){
        pData[i]=theOther.pData[i];
    }
    pData[elementNum]='\0';
}
String::String(const char* str){
    elementNum = strlen(str);
    pData=(char*)malloc((elementNum+1)*sizeof(char));
    for(int i=0; i<elementNum; i++){
        pData[i]=str[i];
    }
    pData[elementNum]='\0';
}

String::String(char c, int times){
    elementNum=times;
    pData=(char*)malloc((elementNum+1)*sizeof(char));
    for(int i=0; i<elementNum; i++){
        pData[i]=c;
    }
    pData[elementNum]='\0';
}
void String::getStr(char * pBuff){
    for(int i=0; i<elementNum; i++){
        pBuff[i]=pData[i];
    }
    pBuff[elementNum]='\0';
}
void String::print(std::ostream& os){
    for(int i=0; i<elementNum; i++){
        os<<pData[i];
    }
}
char String::getChar(int pos){
    if(pos<0 || pos>=elementNum){
        return 0;
    }
    return pData[pos];
}

String String::concatenate(String string1, String string2){
    String result;
    result.elementNum=string1.elementNum+string2.elementNum;
    result.pData=(char*)malloc((result.elementNum+1)*sizeof(char));
    for(int i=0; i<string1.elementNum; i++){
        result.pData[i]=string1.pData[i];
    }
    for(int i=0; i<string2.elementNum; i++){
        result.pData[string1.elementNum+i]=string2.pData[i];
    }
    result.pData[result.elementNum]='\0';
    return result;
}

bool String::compare(String string1, String string2){
    if(string1.elementNum != string2.elementNum){
        return false;
    }
    for(int i=0; i<string1.elementNum; i++){
        if(string1.pData[i] != string2.pData[i]){
            return false;
        }
    }
    return true;
}
void String::copy(String& string1, String string2){
    free(string1.pData);
    string1.elementNum=string2.elementNum;
    string1.pData=(char*)malloc((string1.elementNum+1)*sizeof(char));
    for(int i=0; i<string1.elementNum; i++){
        string1.pData[i]=string2.pData[i];
    }
    string1.pData[string1.elementNum]='\0';
}
