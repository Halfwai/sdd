function getHighest(input){
    let max = input[0];
    for(let i = 1; i < input.length; i++){
        if(input[i] > max){
            max = input[i];
        }
    }
    return max;
}



function testRetVal()
{
    var input = [1, 2, 3, 4, 5, 6];
    var res = getHighest(input);

    if (res == undefined){
        return false;
    } else {
        return true;
    }
}

function testResInArray(){
    var input = [1, 2, 3];
    var res = getHighest(input);

    if (res === 1 || res == 2 || res == 3){
        return true;
    } else {
        return false;
    }
}

function testCorrectRes(){
    var input = [1, 2, 3];
    var res = getHighest(input);

    if (res == 3){
        return true;
    } else {
        return false;
    }
}

let res = testRetVal();
if (res) {
    console.log("testRelVal passed");
} else {
    console.log("testRelVal failed");
}

res = testResInArray();
if (res) {
    console.log("testResInArray passed");
} else {
    console.log("testResInArray failed");
}

res = testResInArray();
if (res) {
    console.log("testResInArray passed");
} else {
    console.log("testResInArray failed");
}

res = testCorrectRes();
if (res) {
    console.log("testCorrectRes passed");
} else {
    console.log("testCorrectRes failed");
}