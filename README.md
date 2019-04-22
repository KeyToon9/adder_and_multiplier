##使用数字电路的思维写一个加法器和乘法器

#加法器的原理：
两数相异或得到无进位的数，两数相与得到进位的数
上面得到的结果继续进行这样的方法，最后可以得到结果

#乘法器原理
设定一个暂存变量，初始化为0
判断乘数个位是否等于1，是的话就直接将被乘数与暂存变量相加
如果等于0，就直接输出暂存变量
接着被乘数左移1位，乘数右移1位
重复操作，直到乘数等于0
