#include<iostream>

using namespace std;

void quick_sort(int s[],int left,int right)
{
	//������������ ���� ��ʼ������
	int i = left; //left��right��ÿһ���������ǹ̶��ģ�������Ҫ��i��jȥ����
	int j = right;
	int temp;
	int pivot = s[(left+right)/2];//��׼��Ϊ��ǰ������м�λ��

	while(i<=j)//ֻҪû�в����꣬����ѭ��
	{
		//i��j��ʼ�������ֱ���һ���Ȼ�׼��ĺͱȻ�׼С��
		while(s[i]<pivot)	i++;
		while(s[j]>pivot)  j--;
		//�ҵ�����������������������򽻻�λ��
		if(i<=j)
		{
			temp=s[i];
			s[i]=s[j];
			s[j]=temp;

			i++;//������Ϻ��������
			j--;
		}
	}
	if(left<j)   quick_sort(s,left,j);//ֻҪjû�е�������߼����ֶ�����
	if(i<right)	 quick_sort(s,i,right);
}
int main(){
	int s[]={5,4,8,6,7,9,1,3,2,10};
	int length = sizeof(s)/sizeof(s[0]);
	quick_sort(s,0,length-1);
	for(int i=0;i<length;i++)
		cout<<s[i]<<" ";
	return 0;
}