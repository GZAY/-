#include<iostream>
using namespace std;
int ans;
int f(int n, int step){//�ݹ���ж���������������˼��1.ÿһ�����е�����Ҫ��2.�����������ٽ�����
	//���step������ԭ������Ŀ�жԲ���������Ҫ��ÿ�εݹ���Ҫ�жϲ����Ƿ�Ϊż��
	if(n<0)return 0;
	if(n==0&&step%2==0)//��ÿһ�ַ��������ж���ż��
		ans++;
	f(n-1,step+1);
	f(n-2,step+1);//̨�����ڼ��٣����������ӣ��߷��Ĳ�ͬ����Ӱ�첽���Ĳ�ͬ��ͬʱ��һ����������̨��������Ҳ��ͬ
	return ans;
}
int main(){
	int n=39,step=0;
	f(n,step);
	cout<<ans<<endl;
}