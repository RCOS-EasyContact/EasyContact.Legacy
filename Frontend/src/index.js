import React from 'react';
import ReactDOM from 'react-dom';
import { Provider } from 'react-redux';
import { createStore } from 'redux';

import './index.css';
import rootReducer from './reducers/Conversations';
import App from './App';


//for future login page connet pipe
//import * as serviceWorker from './serveWorker';

const store = createStore(rootReducer);
ReactDOM.render(
    <Provider store={store}>
        <App />
    </Provider>,
    document.getElementById('root'));
//serviceWorker.unregister();
export default concersations;