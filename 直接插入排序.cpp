#include<iostream>
#include<algorithm>
using namespace std;
/*
ֱ�Ӳ�������

*/

void zhijie_sort(int s[], int len){
	int t,i,j;
	for(i=1;i<len;i++)//i����Ҫ���������±�
	{
		t=s[i];//������ʱ�����Ҳ���ǽ�Ҫ��������������ǰ��i-1�������бȽ�
		for(j=i-1;j>=0;j--)//j����i֮ǰҪ���������ĸ���,��������0��ֹͣ
		{
			if(s[j]>t)//ֻҪ��Ҫ����������
				s[j+1]=s[j];//��s[j]�����ƣ�ֱ���Ƶ���һ��
			else
				break;
		}
		s[j+1]=t;//��Ϊѭ�����j��0��Ϊ-1�ų�������Ҫ��һ
	}
}
int main(){
	int s[]={64,2,0,8,6,999,7,0,-8,6,6,6,1,76,1,1};
	int length=sizeof(s)/sizeof(s[0]);
	//sort(s,s+length);
	zhijie_sort(s,length);
	for(int i=0;i<length;i++)
		cout<<s[i]<<" ";
	return 0;
}