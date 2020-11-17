const { Api, JsonRpc, RpcError } = require('eosjs');
const { JsSignatureProvider } = require('eosjs/dist/eosjs-jssig');      // development only
const fetch = require('node-fetch');                                    // node only; not needed in browsers
const { TextEncoder, TextDecoder } = require('util'); 
const transaction=(data)=>{

    let privatekey = '5KhAuZV74LURLMNftfXQpynlx2a6REtZqY4Hf2fuclDMgYueWNy';//用来签名的default私钥
    let asignatureProvider = new JsSignatureProvider([privatekey]);
    const rpc = new JsonRpc("http://117.132.185.237:1101/", {fetch});
    const api = new Api({ rpc:rpc, signatureProvider:asignatureProvider, textDecoder: new TextDecoder(), textEncoder: new TextEncoder() }); 
    let result = await api.transact({
        actions: [{
          account: 'project.l1',
          name: 'add',
          authorization: [{
            actor: "project.l1",
            permission: 'default',
          }],
          data: data,
        }]
    }, {
        blocksBehind: 3,
        expireSeconds: 30,
    });

    if(result){
        return {success:true,data:result}
    } else {
        return {success:false,data:result}
    }
}
//合约定义的接收的参数
let data = {
    test:"",
    testb:"",
    testc:""
}
transaction(data);