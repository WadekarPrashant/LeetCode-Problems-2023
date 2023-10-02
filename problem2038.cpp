class Solution {
public:
    bool winnerOfGame(string colors)
    {
        int a=0;
        int b=0;
        for(int i=0;i<colors.size();)
        {
            char ch=colors[i];
            int count=0;
            while(i<colors.size())
            {
                if(colors[i]!=ch)break;
                i++;
                count++;
            }
            if(count>=3)
            {
                if(ch=='A')
                {
                    
                 a+=count-2;
                }
                else
                {
                    b+=count-2;
                }
            }
        }
        return a>b;
    }
};
