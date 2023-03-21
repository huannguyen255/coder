// const soA = document.getElementById("so_a");
// const soB = document.getElementById("so_b");

function isPrime(num) {
    if (num < 2) {
        return false;
    }
    for (let i = 2; i <= Math.sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

function sumPrime() {
    let a = document.getElementById("a").value;
    let b = document.getElementById("b").value;

    a = parseInt(a);
    b = parseInt(b);

    let sum = 0;
    for (let i = a; i <= b; i++) {
        if (isPrime(i)) {
            sum += i;
        }
    }

    document.getElementById("result").innerHTML = "Các số nguyên tố trong khoảng từ " + a + " đến " + b + " là: " + sum;
}


function numberOneTriangle(a) {
    let c = document.getElementById("c").value;
    let tamGiac = ""
    for (let i = 0;i<=c;i++) {
        for (let j=0;j<=i;j++) {
            tamGiac = tamGiac + "*"
		}
		tamGiac = tamGiac + "<br>"
    }
    document.getElementById("triangle").innerHTML = tamGiac
};






