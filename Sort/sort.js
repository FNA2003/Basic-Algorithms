


function main(arr) {

  bubbleSort(arr, false);

  for (x of arr) {
    console.log(x);
  }
}

function bubbleSort(array, ascending) {
  if (typeof(array) != "object" || typeof(ascending) != "boolean") { 
    console.warn("Wrong type of argument(s)!");
    return; 
  }
  let isSorted = true;
  let iterations = 1;

  while(1) {
    if (iterations >= array.length * array.length) {
      console.error("Iterations overflow in Bubble Sort algorithm!");
      return;
    }

    for (let i = 0; i < (array.length - 1); i++) {
      if ((array[i] > array[i+1] && ascending) ||
          (array[i] < array[i+1] && !ascending)) {

        [array[i], array[i+1]] = [array[i+1], array[i]];
        isSorted = false;
      }
      iterations ++;
    }

    if (isSorted) { return array; }
    isSorted = true;
  }
}


const fs = require('fs');

fs.readFile('list.json', (err, data) => {
  if (err) throw err;
  const array = JSON.parse(data);

  main(array);
});