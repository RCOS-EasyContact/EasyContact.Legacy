import React from 'react';

import './Chat-Title.css';

const ChatTitle = (props) => {
    return (
        <div id="chat-title">
            <span>{props.selectedConversation.title}</span>
            <img src={require("../../images/icons/trash-logo.svg").default} alt="Delete Conversation" />
        </div>
    );
}

export default ChatTitle;