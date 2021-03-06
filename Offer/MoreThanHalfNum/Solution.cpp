class Solution
{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        if (numbers.size() < 1)
        {
            return 0;
        }

        int candidate = numbers[0];
        int num = 1;
        int size = numbers.size();
        for (int i = 1; i < size; i++)
        {
            if (numbers[i] == candidate)
            {
                num++;
            }
            else
            {
                if (num >= 1)
                {
                    num--;
                }
                else
                {
                    candidate = numbers[i];
                    num = 1;
                }
            }
        }

        if (num > 0)
        {
            int count = 0;
            for (int i = 0; i < size; i++)
            {
                if (numbers[i] == candidate)
                {
                    count++;
                }
            }
            if (count > size / 2)
            {
                return candidate;
            }
        }

        return 0;
    }
};