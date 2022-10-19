%%-----------------D=Distance------%%%%%%%%%%%%%%%%%----P=presence---------
%%s => servo%%%%%%%%%%%%%%%%%%||MM & MD => Moteur1||%%%%%%%%%||MA & MR => Moteur2||%%%
clear all port;
a = arduino('COM8', 'Uno','libraries',{'Servo','ultrasonic'});%%%COM verifiha !!!
s = servo(a,'D9');
for angle = 0:0.01:0.25
        writePosition(s, angle);
        pause(0.1);
end
writeDigitalPin(a,'D4',0);%%%%% MM
writeDigitalPin(a,'D3',0);%%%%% MD
writeDigitalPin(a,'D6',0);%%%%% MA
writeDigitalPin(a,'D5',0);%%%%% MR
sensor = ultrasonic (a,'D13', 'D12');
P = readDigitalPin(a,'D2'); %%%%%-P-%%%%
D=readDistance(sensor); %%%%%-D-%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%-+INIT+-%%%%%%%%%%%%%%%%%%
%%%%%pas de voiture && pos AV => RECULE %%%%%
while(P==0)
    P = readDigitalPin(a,'D2');
    writeDigitalPin(a,'D6',0);%%%%% MA
    writeDigitalPin(a,'D5',0);%%%%% MR
    pause(10); %%%%pause pour le retour !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
end
%%%pas de voiture && Dist>0 => Servo->1/2 && DESCENDRE %%%%
while(D>0.047 && P==0) %%%%%%%distance
    P = readDigitalPin(a,'D2');
    D=readDistance(sensor);
    writeDigitalPin(a,'D4',0);%%%%% MM
    writeDigitalPin(a,'D3',1);%%%%% MD
    for angle = 0:0.01:0.25
        writePosition(s, angle);
        pause(0.1);
    end

end
M=zeros(1,3);
%%%%%%%%%%%%%%%%%%%%+-fonctionnement-+%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
while(P==1 && D==0.047) %%%%%%%%%%%distance 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%Place1%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
P = readDigitalPin(a,'D2');
D=readDistance(sensor);
if(M(1,1)==0) %%%%% place 1 vide 
        while(D<0.1455) %%%%%% distance
            D=readDistance(sensor);
            writeDigitalPin(a,'D4',1);%%%%% MM 
            writeDigitalPin(a,'D3',0);%%%%% MD
            for angle = 0:0.01:0.02 %%%%% tourner a la 1 ere place
                writePosition(s, angle);
                pause(0.1);
            end
        end
        %%%%%%%%%%%%%%%%%%%%%%avantiiii%%%%%%%%%%%%%%%%%%%%%%%%
        writeDigitalPin(a,'D6',1);%%%%% MA
        writeDigitalPin(a,'D5',0);%%%%% MR
        pause(10); %%%%%% pause pour l'avancement !!!!!!!!!!!!!!!!!!!!!!!!!
        M(1,1)=1; %%%%%%% place 1 pleine %%%%%%%%%%%%%
        writeDigitalPin(a,'D6',0);%%%%% MA
        writeDigitalPin(a,'D5',1);%%%%% MR
        pause(10); %%%%%% pause pour le retour !!!!!!!!!!!!!!!!!!!!!!!!!
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        while(D>0.047) %%%%%%%%%% distance
            D=readDistance(sensor);
            writeDigitalPin(a,'D4',0);%%%%% MM 
            writeDigitalPin(a,'D3',1);%%%%% MD
            for angle = 0:0.01:0.25 %%%%% tourner a la pos init
                writePosition(s, angle);
                pause(0.1);
            end
        end
    else 
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%Place 2 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        if(M(1,2)==0) %%%%%% place 2 vide

            while(D<0.1455) %%%%%%% distance
            D=readDistance(sensor);
            writeDigitalPin(a,'D4',1);%%%%% MM 
            writeDigitalPin(a,'D3',0);%%%%% MD
            for angle = 0:0.01:0.25 %%%%% tourner a la 2eme place
                writePosition(s, angle);
                pause(0.1);
            end
            end
        %%%%%%%%%%%%%%%%%%%%%%avantiiii%%%%%%%%%%%%%%%%%%%%%%%%
        writeDigitalPin(a,'D6',1);%%%%% MA
        writeDigitalPin(a,'D5',0);%%%%% MR
        pause(10); %%%%%% pause pour l'avancement !!!!!!!!!!!!!!!!!!!!!!!!!
        M(1,2)=1; %%%%%%% place 2 pleine %%%%%%%%%%%%%
        writeDigitalPin(a,'D6',0);%%%%% MA
        writeDigitalPin(a,'D5',1);%%%%% MR
        pause(10); %%%%%% pause pour le retour !!!!!!!!!!!!!!!!!!!!!!!!!
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        while(D>0.4) %%%%%%%%%% distance 
            D=readDistance(sensor);
            writeDigitalPin(a,'D4',0);%%%%% MM 
            writeDigitalPin(a,'D3',1);%%%%% MD
            for angle = 0:0.01:0.25 %%%%% tourner a la pos init
                writePosition(s, angle);
                pause(0.1);
            end
        end
                else
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%Place 3 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                if(M(1,3)==0) %%%%%place3 vide
                    while(D<0.1455) %%%%%%% distance 
            D=readDistance(sensor);
            writeDigitalPin(a,'D4',1);%%%%% MM 
            writeDigitalPin(a,'D3',0);%%%%% MD
            for angle = 0:0.01:0.4 %%%%% tourner a la 3 eme place
                writePosition(s, angle);
                pause(0.1);
            end
                    end
        
        %%%%%%%%%%%%%%%%%%%%%%avantiiii%%%%%%%%%%%%%%%%%%%%%%%%
        writeDigitalPin(a,'D6',1);%%%%% MA
        writeDigitalPin(a,'D5',0);%%%%% MR
        pause(10); %%%%%% pause pour l'avancement !!!!!!!!!!!!!!!!!!!!!!!!!
        M(1,3)=1; %%%%%%% place 3 pleine %%%%%%%%%%%%%
        writeDigitalPin(a,'D6',0);%%%%% MA
        writeDigitalPin(a,'D5',1);%%%%% MR
        pause(10); %%%%%% pause pour le retour !!!!!!!!!!!!!!!!!!!!!!!!!
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        while(D>0.047) %%%%%%%%%% distance 
            D=readDistance(sensor);
            writeDigitalPin(a,'D4',0);%%%%% MM 
            writeDigitalPin(a,'D3',1);%%%%% MD
            for angle = 0:0.01:0.25 %%%%% tourner a la pos init
                writePosition(s, angle);
                pause(0.1);
            end
        end
                end
        end
end
end