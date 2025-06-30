# Bit Manipulation Notes

```cpp
OddEven(int& n):
	if (n & 1) print("Odd")
	else print("Even")
```

```cpp
getIthBit(int& n, int i):
	int mask = 1 << i;
	return (n & mask) > 0 ? 1 : 0;
```

```cpp
clearIthBit(int& n, int i):
	int mask = ~(1 << i);
	n = n & mask;
```

```cpp
setIthBit(int& n, int i):
	int mask = 1 << i;
	n = n | mask;
```

```cpp
updateIthBit(int& n, int i, int v):
	clearIthBit(n, i);
	int mask = v << i;
	n = n | mask;
```

```cpp
clearLastIBits(int& n, int i):
	int mask = -1 << i;
	n = n & mask;
```

```cpp
clearBitsInRange(int& n, int i, int j):
	int a = (-1) << (j + 1)
	int b = (1 << i) - 1;
	int mask = a | b;
	n = n & mask;
```

```cpp
ReplaceBits(int& n, int i, int j, int m):
	clearBitsInRange(n, i, j);
	int mask = m << i;
	n = n | mask;
```

```cpp
CheckPowerOfTwo(int& n):
	return n & (n - 1) == 0;
```

```cpp
CountSetBits(int n):
	int cnt = 0;
	while (n > 0) {
		int last_bit = n & 1;
		cnt += last_bit;
		n = n >> 1;
	}
	return cnt;
```

```cpp
(Faster) CountSetBits(int n):
	int cnt = 0;
	while (n > 0) {
		n = n & (n - 1);
		cnt++;
	}
	return cnt;
```

```cpp
convertToBinary(int n):
	int ans = 0;
	int p = 1;
	while (n > 0) {
		int last_bit = n & 1;
		ans += p * last_bit;
		p = p * 10;
		n = n >> 1;
	}
	return ans;
```

```text
Notes:
- A number has log(N) bits.
- num = -1 represents all 31 bits set.
```

---

Let me know if you'd like a section for `bitmask + sliding window`, `trie`, or `XOR tricks` too.
