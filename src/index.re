[%bs.raw {|require('./index.css')|}];

[@bs.module "./registerServiceWorker"]
external registerServiceWorker : unit => unit = "default";

ReactDOMRe.renderToElementWithId(<App />, "root");

registerServiceWorker();
