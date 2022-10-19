i=imread('carplate2.jpg');
b=imresize(i,[400 NaN]);
b=rgb2gray(b);
g=medfilt2(b,[3 3]);
se=strel('disk',1);
gi=imdilate(g,se);
ge=imerode(g,se);

gdiff=imsubtract(gi,ge);
gdiff=mat2gray(gdiff);
gdiff=conv2(gdiff,[1 1;1 1]);
gdiff=imadjust(gdiff,[0.5 0.7],[0 1],0.1)
B=logical(gdiff);
pause(1);
er=imerode(B,strel('line',0,0));
imshow(B);
out1=imsubtract(B,er);

F=imfill(out1,'holes');

H1=bwmorph(F,'thin',1);
H=imerode(H1,strel('line',3,90));
final=bwlabel(H);
final=bwareaopen(final,100);
pause(2);
imshow(final);



pause(1);
