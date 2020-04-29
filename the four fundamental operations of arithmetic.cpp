#include "pch.h"
#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)//整数加法运算
		{
			int Range = 50; //最大值
			int Num = 5;//数量
			int  OperatorType = 1;//定制运算题目类型：0.加法运算 1.减法运算 2.乘法运算 3.除法运算 4.四则混合运算
			int ResultType = 1;//运算结果类型：0.无 1.只允许为整数 2.两位小数内必须除尽
			int format1 = 1; //每行打印多少个题目
			int format2 = 1;//，若每行题目数量大于1，每个题目之间需要留多空格
			int PrintType = 1;//是否输出到文件0.不通过文件输出  1.通过文件输出
			int a, b;//随机数
			int ans[100];
			int i = 0;
			char type = ' ';//运算符
			int result[100];//答案
			for (i = 1; i <= Num; i++) {

			}
			for (i = 1; i <= Num; i++) {
				Assert::AreEqual(ans[i], result[i]);
			};
			
		}
		TEST_METHOD(TestMethod2)//小数除法法运算（除数非0）
		{
			int Range = 10; //最大值
			int Num = 3;//数量
			int  OperatorType = 3;//定制运算题目类型：0.加法运算 1.减法运算 2.乘法运算 3.除法运算 4.四则混合运算
			int ResultType = 2;//运算结果类型：0.无 1.只允许为整数 2.两位小数内必须除尽
			int format1 = 1; //每行打印多少个题目
			int format2 = 1;//，若每行题目数量大于1，每个题目之间需要留多空格
			int PrintType = 1;//是否输出到文件0.不通过文件输出  1.通过文件输出
			float a = 18, b =3 ;
			float ans = 6.0;
			float result = a / b;




			Assert::AreEqual(ans, result);
		}
		TEST_METHOD(TestMethod3)//小数除法运算（除数为0）
		{
			int Range = 50; //最大值
			int Num = 4;//数量
			int  OperatorType = 3;//定制运算题目类型：0.加法运算 1.减法运算 2.乘法运算 3.除法运算 4.四则混合运算
			int ResultType = 2;//运算结果类型：0.无 1.只允许为整数 2.两位小数内必须除尽
			int format1 = 1; //每行打印多少个题目
			int format2 = 1;//，若每行题目数量大于1，每个题目之间需要留多空格
			int PrintType = 1;//是否输出到文件0.不通过文件输出  1.通过文件输出
			float a = 18, b = 0;
			float ans = 0;
			float result = 0;








			Assert::AreEqual(ans, result);
		}
	};
}
