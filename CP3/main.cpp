#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#define NUM 7

using namespace std;

bool statistics(const char *path, int ball_16[], int len);


int main(void){
	string filename;
	int ball_16[33] = {0};
	int len = 33;

	cout << "�������ļ���" << endl;
	cin >> filename;
	if(statistics(filename.c_str(),ball_16),33){
		for(int i = 0; i<len; i++){
			cout << "��" << i+1 << "����ִ�����" << ball_16[i] << endl;
		}
	}
	else{
		cerr << "ͳ�Ƴ���" << endl;
	}

	system("pause");
	return 0;
}

bool statistics(const char* path,int ball_16[], int len){
	int result[NUM];
	ifstream file;
	int i = 0;
	if(!path){
		cerr<<"path is NULL" << endl;//��׼������
		return false;
	}

	file.open(path);
	if(file.fail()){
		cerr << "�������ļ�����" << strerror(errno) << endl;
		//strerror �Ѵ����ŷ���Ϊ�ַ�������ӡ����  srrnoϵͳ�Դ�������
		return false;
	}
	do{
		i = 0;
		for(i=0; i<NUM;i++){
			file >> result[i];
			if(file.eof()){  //file.eof() �ж��ļ���ȡ�Ƿ�ﵽβ�� ������feof�෴
				break;
			}

			if(file.fail()){
				cerr <<"��ȡ�ļ�ʧ�ܣ�ԭ��" << strerror(errno) << endl;
				break;
			}
		}

		if(i == 0) break;//��¼��������
		if(i < (NUM)){
			cerr << "������" << i << "����¼��Ԥ�ڶ����߸�" << endl;
			file.close();
			return false;
		}

		for(i=0; i<NUM; i++){
			cout<<" "<<result[i];
		}
		cout << endl;

		//�Զ�������ݽ���ͳ��
		for(i=0; i<NUM-1; i++){
			int index = *(result + i) - 1;
			if(index >= 0 && index < 33){
				(*(ball_16 + index))++;
			}
		}
	}while(1);

	file.close();
	return true;
}