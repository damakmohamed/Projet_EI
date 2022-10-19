clear a;
a = arduino('COM9', 'Uno','libraries',{'Servo','ExampleLCD/LCDAddon'});
s = servo(a,'D9');
writePosition(s, 0);
pause(1); 
C1 = readDigitalPin(a,'D8');
C2 = readDigitalPin(a,'D13');
p=9;
lcd = addon(a,'ExampleLCD/LCDAddon','RegisterSelectPin','D2','EnablePin','D3','DataPins',{'D4','D5','D6','D7'});
initializeLCD(lcd);
printLCD(lcd,'bienvenue :)');
printLCD(lcd,'Places disp = 9');
%%%%%%%%%%%%%%%%%%%%%%entrer%%%%%%%%%%%%%%%%%%%%%%
while(p>-1)
    C1 = readDigitalPin(a,'D8');
    C2 = readDigitalPin(a,'D13');
    if(C1==1 && p>0 )
        writePosition(s, 0.5);
        pause(2);
        p=p-1;
        pause(2);
        writePosition(s, 0);
        pause(3); 
    end


%%%%%%%%%%%%%%%%%%%%%%%sortir%%%%%%%%%%%%%%%%%%%%%
if(C2==1 && p<9 )
        writePosition(s, 0.5);
        pause(2);
        p=p+1;
        pause(2);
        writePosition(s, 0);
        pause(3);
end

%%%%%%%%%%%%%%%%%%Affichage%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
     
            if(p==9)
                clearLCD(lcd);
                printLCD(lcd,'Bienvenue :)');
                printLCD(lcd,'Places disp = 9');
                pause(2);
            else
            if(p==8)
            clearLCD(lcd);
            printLCD(lcd,'Bienvenue :)');
            printLCD(lcd,'Places disp = 8');
            pause(2);    
            else
                if(p==7)
                    clearLCD(lcd);
                    printLCD(lcd,'Bienvenue :)');
                    printLCD(lcd,'Places disp = 7');
                    pause(2);
                else
                    if(p==6)
                        clearLCD(lcd);
                        printLCD(lcd,'Bienvenue :)');
                        printLCD(lcd,'Places disp = 6');
                        pause(2);
                    else
                        if(p==5)
                            clearLCD(lcd);
                            printLCD(lcd,'Bienvenue :)');
                            printLCD(lcd,'Places disp = 5');
                            pause(2);
                        else
                                if(p==4)
                            clearLCD(lcd);
                            printLCD(lcd,'Bienvenue :)');
                            printLCD(lcd,'Places disp = 4');
                            pause(2);
                        else
                                if(p==3)
                            clearLCD(lcd);
                            printLCD(lcd,'Bienvenue :)');
                            printLCD(lcd,'Places disp = 3');
                            pause(2);
                        else
                                if(p==2)
                            clearLCD(lcd);
                            printLCD(lcd,'Bienvenue :)');
                            printLCD(lcd,'Places disp = 2');
                            pause(2);
                            else
                                if(p==1)
                            clearLCD(lcd);
                            printLCD(lcd,'Bienvenue :)');
                            printLCD(lcd,'Places disp = 1');
                            pause(2);
                                else
                            if(p==0)
                                clearLCD(lcd);
                                printLCD(lcd,'parking');
                                printLCD(lcd,'plein');
                                pause(2);
                            end
                                end
                                end
                                end
                                end
                        end
                    end
                end
            end
            end
end


            