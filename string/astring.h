
#ifndef ASTRING_H
#define ASTRING_H
#define defaultsize=128;
class Astring{
public:
    //���캯��  maxlength
    Astring(int sz=defaultsize);
    //maxsize
    Astring(const char *init);
    //copy
    Astring(const Astring& ob);
    //�ͷŶ�̬�ռ䣬����
    ~Astring(){delete []ch;}
    int length()const{return curlength;}//����*this
    Astring& operator()(int pos,int len);//p158
    int operator == (Astring& ob)const{return strcmp(ch,ob.ch)==0;}
    int operator != (Astring& ob)const{return strcmp(ch,ob.ch)==1;}
    int operator !()const{return curlength==0;}
    Astring& operator=(Astring& ob);
    Astring& operator+=(Astring& ob);
    char& operator[](int i);
    int findd(Astring& pat)const;
private:
    char *ch;
    int curlength;
    int maxsize;

};
#endif // ASTRING_H
