constexpr int square(int x)
{
	return x*x;
}

constexpr int the_answer()
{
	return 42;
}

int main()
{
  constexpr int cVar = 42;
	int test_arr[square(3)];
	bool ret = (
		(square(the_answer()) == 1764) &&
		(sizeof(test_arr)/sizeof(test_arr[0]) == 9) &&
    (cVar == the_answer())
	);
	return ret ? 0 : 1;
}
