
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Father {
private:
    int money;
    
protected:
    int room_key;
    int room_car;
    
public:
    int phone;
    int address;
    
    void working(void)
    {
        cout<<"father working"<<endl;
    }
    
    int getMoney(void)
    {
        return money;
    }
    void setMoeny(int money)
    {
        this->money = money;
    }
};

class Son : public Father {
private:
    int book;
    using Father::phone;
    
public:
    using Father::room_car;
    //using Father::money; //�޷��ı丸��private���͵�����

    void learning(void)
    {
        cout<<"son learning"<<endl;
    }
    
    void getKey(void)
    {
        //s.money = 10; //private����,����Ҳ�޷�����
        room_key = 1;   //protected����,������Է���
    }
};

class Daughter : protected Father {
private:

public:
    void dancing(void)
    {
        cout<<"daughter dancing"<<endl;
        room_key = 1; //���ܺ��ּ̳�,���������ڲ�ʹ�ø���ʱ�޲��
    }
    
    void working(void) //��д
    {
        cout<<"daughter working"<<endl;
    }
};

int main(int argc, char **argv)
{
    Son s;
    Daughter d;
    
    //s.money = 10; //private����,�ⲿ�޷�����
    s.setMoeny(10);
    
    //s.room_key = 1; //protected����,�ⲿ�޷�����
    s.getKey();
    
    s.working(); //public,�ⲿ����ֱ�ӷ���
    s.learning();
    
    s.room_car = 1; //���ཫ���Ϊ��public,ʹ�ÿ��Է���
    //s.phone = 1; //���ཫ���Ϊ��private,ʹ�ò��ܷ���
    
    d.dancing(); //�Լ�������û��
    //d.working(); //protected�̳�,���෽����Ϊprotected,�ⲿ�޷�����
    d.working();
    
    return 0;
}