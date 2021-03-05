clear;
clc;
syms t v x
fid=fopen('.\program\result.txt','r');
x=fscanf(fid,'%f %f\n',[2,inf]);
plot(x(1,:),x(2,:));
hold on;
xlabel('detT');
ylabel('v');

