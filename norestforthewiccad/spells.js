const express = require('express');
const router = express.Router();

let spells = 
   [
      {
         id: 1001, 
         name: "Rabbit foot positivity", 
         ingredients: [
            {name:"Foot of rabbit"}, 
            {name:"Juice of beetle"}], 
         result: "Good luck"
      },
      {
         id:1002,
         name: "Fox exeunta", 
         ingredients: [
            {name:"Foul of lion"}, 
            {name:"Spirit of hobo"}], 
         result: "Fox removed",
      }, 
      {
         id:1003, 
         name: "Hackus maximum", 
         ingredients: [
            {name:"Oxygenated hydrogen juice"}, 
            {name:"Effluent of bean"},
            {name:"Heat of joy"}], 
         result: "Fast coding"
      }
   ];

// get all spells
router.get('/', function(req, res){
    res.json(spells);
});
// get a specific spell
router.get('/:id', function(req, res){
   const spellId = req.params['id'];
   const spell = findSpell(spells, spellId);
   res.json(spell);
});
// update a specific spell
router.put('/:id', function(req, res){
   const spellId = req.params['id'];
   const spell = editSpell(spells, spellId, req.body);
   res.json(spell);
});
// add a new spell
router.post('/', function(req, res){
    let spell = req.body;
    spells.push(spell);
    res.json(spells[3]);
});

module.exports = router;

function findSpell(spells, spellId){
    for (let i = 0; i < spells.length; i++){
        if (spells[i].id == spellId){
            return spells[i];
        }
   }
   return null;
}

function editSpell(spells, spellId, editedSpell){
    for (let i = 0; i < spells.length; i++){
        if (spells[i].id == spellId){
            spells[i] = editedSpell;
            return spells[i];
        }
   }
   return null;
}
