/*************************************************************************************
先将整型数组转换成String数组，然后将string数组排序，最后将排好序的字符串数组拼接出来。关键就是制定排序规则。
 * 排序规则如下：
 * 若ab > ba 则 true，
 * 若ab < ba 则 false，
 * 若ab = ba 则 fasle；
 * 解释说明：
 * 比如 "3" < "31"但是 "331" > "313"，所以要将二者拼接起来进行比较
**************************************************************************************/
class Solution {
public:
    string PrintMinNumber(vector<int> numbers)
    {
        string result;
        int length = numbers.size();
        if(length == 0)
            return result;
        vector<string> temp;
        for(int i = 0; i < length; ++i)
        {
            temp.push_back(to_string(numbers[i]));
        }
        sort(temp.begin(),temp.end(),compares);
        for(int i = 0; i < length; ++i)
        {
            result.append(temp[i]);
        }
        return result;
    }
private:
    static bool compares(string a ,string b)
    {
        string c = a+b;
        string d = b+a;
        return c < d;
    }
};
