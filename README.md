# ThoughtWorks2018textprocessor
Q3：简单文本预处理。输入输入文本和排版宽度，输出处理后的英文单词/空格及行号。  

Code is compiled on Ubuntu with g++  
```
chmod +x build.sh
./build.sh
```
#### 通过所有测试用例 Demo 
in: The main theme of education in engineering school is learning to teach yourself  
20  
The(1); (1);main(1); (1);theme(1); (1);of(1); (1);education(1,2); (2);in(2); (2);engineering(2,3); (3);school(3); (3);is(3); (3);learning(3,4); (4);to(4); (4);teach(4); (4);yourself(4);
#### 异常测试\#1 排版宽度异常
in: So  many whitespaces  
5  
out: "ERROR: Width out of range!"  
#### 异常测试\#2 异常字符
in: So 5  many whitespaces!  
20  
out: "ERROR: Invalid character detected!"  
