#include "pch.h"
#include "CppUnitTest.h"
#include "..\Personal project\main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
        TEST_METHOD(TestMethod1)            //check if textSegmentation works
        {
            std::string argument("吉娣每次看到安娜，都爱慕她，并且想象她一定会穿紫色衣服，可是现在看到她穿着黑色衣服，吉娣才觉得以前没有充分领略她的真正魅力。");
            auto result(textSegmentation(argument));
            /*
            printf("Having %d slice...\n",result.size());
            putchar('{');
            for (auto it : result)
            {
                if (it == result.front()) printf("%s", it.c_str());
                else printf(", %s", it.c_str());
            }
            putchar('}');
            putchar(10);
            */
        }

        TEST_METHOD(TestMethod2)            //check if vecConstruct works
        {
            std::string argument("吉娣每次看到安娜，都爱慕她，并且想象她一定会穿紫色衣服，可是现在看到她穿着黑色衣服，吉娣才觉得以前没有充分领略她的真正魅力。");
            auto temp(textSegmentation(argument));
            refer = temp;
            auto result(vecConstruct(temp));
            /*
            printf("The vector is %d", result.size());
            putchar('{');
            for (auto it : result)
            {
                if (it == result.front()) printf("%d", it);
                else printf(", %d", it);
            }
            putchar('}');
            putchar(10);
            */
        }
        TEST_METHOD(TestMethod3)            //check if calcDistance works fine
        {
            std::vector<int> argument1({0,11,3,12,-4}), argument2({ 0,0,0,0,0 });
            double expected(17.02938636592640116613332182);
            auto result(calcDistance(argument1, argument2));
            Assert::IsTrue(std::abs(expected - result) < 0.0000001);    //compare two decimal
        }

        TEST_METHOD(TestMethod4)            //check if textSegmentation right
        {
            //std::string argument("我爱中国");
            //std::vector<std::string> expected({"我爱", "爱中", "中国"});
            std::string argument("abcd");       //cannot use Chinese in test environment
            std::vector<std::string> expected({"ab", "bc", "cd"});
            auto result(textSegmentation(argument));
            for (int i = 0; i < expected.size(); ++i)
            {
                Assert::AreEqual(result.at(i), expected.at(i));
            }
        }

        TEST_METHOD(TestMethod5)            //check if vecConstruct right
        {
            std::vector<std::string> argument({ "ab", "bc", "cd" });
            std::vector<int> expected({ 1,1,1 });
            refer = argument;
            auto result(vecConstruct(argument));
            Assert::IsTrue(result.size() == 3);
            for (auto it : result)
            {
                Assert::IsTrue(it == 1);
            }
        }

        TEST_METHOD(TestErr1)            //check empty input
        {
            std::string argument("");    
            auto result(textSegmentation(argument));
            Assert::IsTrue(result.empty());
        }
	};
}
