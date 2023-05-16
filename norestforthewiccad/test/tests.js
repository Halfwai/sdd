// ps aux | grep node


var chai = require('chai');
var chaiHttp = require('chai-http');
var assert = require('assert');

chai.use(chaiHttp);

describe('Test top level / route', () => {
    it('it should have a 200 status code', (done) => {
        chai.request('http://localhost:3000') // the top level web address
        .get('/') // the route to add to the top level address
        .end((err, res) => { // what to do once the request returns
            assert.equal(res.status, 200); // check we have the 200 OK HTTP code
            done(); // finish up
        });
    });

    it('it should send the right message', (done) => {
        chai.request('http://localhost:3000')
        .get('/')
        .end((err, res) => {
        let data = JSON.parse(res.text);
            assert.equal(data.message, 'Welcome to the norestforthewiccad API');
            done();
        });
    }); 
});



describe('Test spells route', () => {
    it('it should have a 200 status code', (done) => {
        chai.request('http://localhost:3000') // the top level web address
        .get('/spells') // the route to add to the top level address
        .end((err, res) => { // what to do once the request returns
            assert.equal(res.status, 200); // check we have the 200 OK HTTP code
            done(); // finish up
        });
    });
});

describe('Test spells response', () => {
    it('it should have some data on  3 spells', (done) => {
        chai.request('http://localhost:3000') // the top level web address
        .get('/spells') // the route to add to the top level address
        .end((err, res) => { // what to do once the request returns
            assert.equal(res.body.length, 3); // check we have the 200 OK HTTP code
            done(); // finish up
        });
    });
});

describe('Test separate spell response', () => {
    it('it should return a spell with the id of 1002', (done) => {
        chai.request('http://localhost:3000') // the top level web address
        .get('/spells/1002') // the route to add to the top level address
        .end((err, res) => { // what to do once the request returns
            assert.equal(res.body.id, 1002); // check we have the 200 OK HTTP code
            done(); // finish up
        });
    });
});

describe('Test adding spells', () => {
    it('it should add a spell to the api', (done) => {
        const newSpell = {
            "id": 1005,
            "name": "Stupid Spell",
            "Ingredients": [{
                "name": "Muck"
            }],
            "result": "You gonna die"
        }
        chai.request('http://localhost:3000') // the top level web address
        .post('/spells') // the route to add to the top level address
        .send(newSpell)
        .end((err, res) => { // what to do once the request returns
            assert.equal(res.body.id, 1005);
            assert.equal(res.body.name, "Stupid Spell"); // check the spell now exists in the api
            done(); // finish up
        });
    });
});

describe('Test updating spells', () => {
    it('it should change a spell already in the api', (done) => {
        const editedSpell = {
            "id": 1001,
            "name": "Rabbit Foot Negativity",
            "Ingredients": [{
                "name": "Rotten rabbit's foot"
            },
            {
                "name": "Dead beetle"
            }],
            "result": "Terrible terrible luck"
        }
        chai.request('http://localhost:3000') // the top level web address
        .put('/spells/1001') // the route to add to the top level address
        .send(editedSpell)
        .end((err, res) => { // what to do once the request returns
            assert.equal(res.body.id, 1001);
            assert.equal(res.body.name, "Rabbit Foot Negativity"); // check the spell now exists in the api
            done(); // finish up
        });
    });
});

