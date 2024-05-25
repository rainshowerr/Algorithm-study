using namespace std;

long long solution(int price, int money, int count)
{
    long long price_sum = 0;
    for(int i = 0; i < count; i++)
        price_sum += price * (i + 1);
    if (money - price_sum < 0)
        return price_sum - money;
    return 0;
}