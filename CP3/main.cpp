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

	cout << "请输入文件名" << endl;
	cin >> filename;
	if(statistics(filename.c_str(),ball_16),33){
		for(int i = 0; i<len; i++){
			cout << "第" << i+1 << "球出现次数：" << ball_16[i] << endl;
		}
	}
	else{
		cerr << "统计出错！" << endl;
	}

	system("pause");
	return 0;
}

bool statistics(const char* path,int ball_16[], int len){
	int result[NUM];
	ifstream file;
	int i = 0;
	if(!path){
		cerr<<"path is NULL" << endl;//标准错误流
		return false;
	}

	file.open(path);
	if(file.fail()){
		cerr << "打开输入文件出错" << strerror(errno) << endl;
		//strerror 把错误编号翻译为字符串并打印出来  srrno系统自带错误编号
		return false;
	}
	do{
		i = 0;
		for(i=0; i<NUM;i++){
			file >> result[i];
			if(file.eof()){  //file.eof() 判断文件读取是否达到尾部 返回与feof相反
				break;
			}

			if(file.fail()){
				cerr <<"读取文件失败，原因：" << strerror(errno) << endl;
				break;
			}
		}

		if(i == 0) break;//记录正常结束
		if(i < (NUM)){
			cerr << "仅读到" << i << "个记录，预期读到七个" << endl;
			file.close();
			return false;
		}

		for(i=0; i<NUM; i++){
			cout<<" "<<result[i];
		}
		cout << endl;

		//对读入的数据进行统计
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