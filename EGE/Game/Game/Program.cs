
List<int> go(int a, int b)
{
    var r = new List<int>() { sol(a + 6, b), sol(a, b + 6)};
    if (a > 1)
        r.Add(sol(a*a, b));
    if (b > 1)
        r.Add(sol(a, b*b));
    return r;

}
Dictionary<string, int> cache = new Dictionary<string, int>();
int sol(int a, int b)
{
    string s = $"{a} {b}";

    if (cache.ContainsKey(s)) {
        return cache[s];
    }

    if (a + b >= 200)
    {
        return -0;
    }
    var m = go(a, b);

    if (m.All(x => x > 0))
    {
        cache[s] = -m.Max();
    }
    else
    {
        cache[s] = -(from x in m where x <= 0 select x).Max() + 1;
    }
    return cache[s];
}

for (int s = 1; s <= 194; s++)
{
    Console.WriteLine($"{s} {sol(3, s)}");
}
