clear all;
close all;

load allData.mat;

reorderFir = randperm(1000000);
reorderSec = randperm(1000000);

reorderFir = reorderFir(1:1000);
reorderSec = reorderSec(1:1000);

switchIdx = find(reorderFir > reorderSec);
tempSave = reorderSec(switchIdx);
reorderSec(switchIdx) = reorderFir(switchIdx);
reorderFir(switchIdx) = tempSave;

reorderFir = reorderFir';
reorderSec = reorderSec';

dlmwrite('RunCollatz.in',[reorderFir reorderSec],'delimiter',' ','precision','%7d');

resultVec = zeros(length(reorderFir),1);
for i = 1:length(reorderFir)
    startNum = reorderFir(i);
    endNum = reorderSec(i);
    relLengths = lengths(startNum:endNum);
    maxLength = max(relLengths);
    maxLength = maxLength(1);
    resultVec(i) = maxLength;
end

dlmwrite('RunCollatz.out',[reorderFir reorderSec resultVec],'delimiter',' ','precision','%7d');