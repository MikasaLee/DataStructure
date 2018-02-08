## 一元多项式的抽象数据类型定义

```
ADT Polynomial{
	
	数据对象:D = {a<sub>i</sub> |a<sub>i</sub> 属于TermSet,i =1,2,...,m。 m => 0
	TermSet中的每个元素包含一个表示系数的实数和表示指数的整数。
	}
	
	数据关系:R1 ={  &lt;a<sub>i-1</sub>,a<sub>i</sub>&gt; | a<sub>i-1</sub>,a<sub>i</sub>属于D,且a<sub>i-1</sub>中的指数值 < a<sub>i</sub>中的指数值i = 2,3,...m}

	基本操作:
		CreatPolyn(&P,m)
		操作结果：输入m项的系数和指数，建立一元多项式P

		DstroyPolyn(&p)
		初始条件：一元多项式P已存在。
		操作结果：销毁一元多项式P。

		PrintPolyn(P)
		初始条件：一元多项式P已存在
		操作结果：打印输出一元多项式P。

		PolynLength(P)
		初始条件：一元多项式P已存在
		操作结果：返回一元多项式P中的项数。
	
		AddPolyn(&Pa,&Pb)
		初始条件：一元多项式Pa和Pb已存在
		操作结果：完成多项式想加运算，即Pa = Pa + Pb,并销毁一元多项式Pb

		SubtractPolyn(&Pa,&Pb)
		操作结果：完成多项式相减运算，即Pa = Pa - Pb，并销毁一元多项式Pb。

		MultiplyPolyn(&Pa,&Pb)
		初始条件：一元多项式Pa和Pb已存在
		操作结果：完成多项式相乘运算，即Pa = Pa x Pb ,并销毁一元多项式Pb。
	
}/ADT Polynomial
```
