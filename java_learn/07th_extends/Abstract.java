//������
abstract class Father {
    public abstract void study(); //�涨���������ʵ�ֵķ���
}

//����
class Son extends Father {
    public void study() { //ʵ�ֳ����ඨ��ķ���
        System.out.println("Son study"); 
    }
}

public class Abstract {
    public static void main(String args[]) {
        //Father father = new Father(); //�����಻��ʵ��������
        Son son = new Son();
        
        son.study();
    }
}