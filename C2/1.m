%Question 1 a
figure('name','1a');
t = -10:0.005:10;
xa = (t+2)==0;
plot(t, xa);
title('Vashni Agrahari 22102213 \delta(t+2)');
ylim([0 1.2]);
xlabel('time');
ylabel('amplitude');

%Question 1 b
figure('name','1b');
xb = ((t+2)==0) - ((t-2)==0);
plot(t, xb);
title('Vashni Agrahari 22102213 \delta(t+2)-\delta(t-2)');
ylim([-1.2 1.2]);
xlabel('time');
ylabel('amplitude');


%Question 1 c
figure('name','1c');
xc = t.*(t>=0);
plot(t, xc);
title('Vashni Agrahari 22102213 t.u(t)');
xlabel('time');
ylabel('amplitude');

%Question 1 d
figure('name','1d');
xd = ((t)>=0)-((t-5)>=0);
plot(t, xd);
title('Vashni Agrahari 22102213 u(t)–u(t-5)');
ylim([0 1.2]);
xlabel('time');
ylabel('amplitude');

%Question 1 e
figure('name','1e');
xe = ((t+1).*((t+1)>=0)) - ((t).*((t)>=0)) + ((t-2).*((t-2)>=0));
plot(t, xe);
title('Vashni Agrahari 22102213 r(t+1) – r(t) + r(t-2)');
xlabel('time');
ylabel('amplitude');

%Question 1 f
figure('name','1f');
xf = (exp(-t).*sin(2*pi*t)) + (exp(-t/2).*cos(5*pi*t));
plot(t, xf);
title('Vashni Agrahari 22102213 exp(-t)sin(2\pit) + exp(-t/2)cos(5\pit)');
xlabel('time');
ylabel('amplitude');

%Question 2 a
figure('name','2a')
n = -5:1:5;
unitstep = n>=0;
xa= n.*unitstep;
stem(-n, xa);
title('Vashni Agrahari 22102213 xa[n] = r[-n]');
xlabel('time');
ylabel('amplitude');

%Question 2 b
figure('name','2b')
n = -5:1:5;
xb= exp(n-1);
stem(n, xb);
title('Vashni Agrahari 22102213 exp[n-1]');
xlabel('time');
ylabel('amplitude');

%Question 2 c
figure('name','2c')
n = -5:1:5;
xc= (n-1).*(n-2==0);
stem(n, xc);
title('Vashni Agrahari 22102213 xc[n] = [n - 1] \delta[n - 2]');
ylim([0 1.2]);
xlabel('time');
ylabel('amplitude');

%Question 2 d
figure('name','2d')
n = -5:1:5;
f1 = (n+1)>=0;
f2 = (-2).*((n)>=0);
f3 = (n-1)>=0;
xd= f1 + f2 + f3;
stem(n, xd);
title('Vashni Agrahari 22102213 xd[n] = u [n + 1] – 2u[ n] + u [n-1]');
ylim([-1.2 1.2]);
xlabel('time');
ylabel('amplitude');

%Question 2 e
figure('name','2e')
n = -5:1:5;
xe= (n+2).*((n+2)>=0) - (n-2).*((n-2)>=0);
stem(n, xe);
title('Vashni Agrahari 22102213 xe[n] = r [n + 2] – r [n - 2]');
ylim([0 5]);
xlabel('time');
ylabel('amplitude');

%Question 2 f
figure('name','2f')
n = -5:1:5;
a = 3;
xf= (a.^n).*cos(2*pi*n);
stem(n, xf);
title('Vashni Agrahari 22102213 xf [n] = a^n cos(2\pin) , a=3');
xlabel('time');
ylabel('amplitude');

%Question 3
figure('name','2');
t = 0:0.005:7;
v1 = (20*exp(-2*t).*((t)>=0)).*(t>=0 & t<=2);
v2 = -10.*((t-2)>=0).*(t>=2 & t<=3);
v3 = 10*(t-2).*((t-2)>=0).*(t>=2 & t<=3);
v4 = 20.*((t-3)>=0).*(t>=3 & t<=5);
v5 = -10*(t-3).*((t-3)>=0).*(t>=3 & t<=5);
v6 = -20.*((t-5)>=0).*(t>=5 & t<=7);
v7 = 10*(t-5).*((t-5)>=0).*(t>=5 & t<=7);
v = v1+v2+v3+v4+v5+v6+v7;
subplot(2,1,1);
plot(t,v);
title('Vashni Agrahari 22102213 Question 2 Function');
xlabel('time');
ylabel('v(t)');
vd = diff(v)./diff(t);
subplot(2,1,2);
plot(((t(1:end-1))+(t(2:end)))/2, vd);
ylim([-20 20]);
title('Vashni Agrahari 22102213 Question 2 Derivative');
xlabel('time');
ylabel('dv(t)/dt');


%Question 4
figure();
n = -2:1:10;
x1 = (5)*(n<=0);
x2 = (5-3*n).*(n>0 & n<=4);
x3 = (-23+n.^2).*(n>4 & n<=8);
x4 = (41)*(n>8);
x = x1+x2+x3+x4;
stem(n,x);
xlabel('time');
ylabel('amplitude');
title('Vashni Agrahari 22102213 x[n]');
