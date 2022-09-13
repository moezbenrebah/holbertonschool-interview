#!/usr/bin/node

// const request = require('request');
// const version = process.argv[2];
// const url = `https://swapi-api.hbtn.io/api/films/${version}/`;

// request(url, async (error, response, body) => {
//   if (!error) {
//     const characters = JSON.parse(body).characters;
//     for (const charId in characters) {
//       await new Promise((resolve, reject) => {
//         request(characters[charId], (error, response, body) => {
//           if (!error) {
//             console.log(JSON.parse(body).name);
//             resolve();
//           }
//         });
//       });
//     }
//   }
// });

const request = require('request');
const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv.slice(2);

const GetData = (l, index) => {
  request.get(l[index], (error, res, body) => {

    const ListSize = l.length;

    if (error) throw error;
    const ReturnValue = JSON.parse(body);
    console.log(ReturnValue.name);

    if (index < (ListSize - 1)) {
      GetData(l, (index + 1));
    }
  });
};

request.get(url, (error, res) => {
  if (error) console.log(error);
  else {
    const ll = JSON.parse(res.body);
    GetData(ll.characters, 0);
  }
});
