export function loadHomeContent() {
    const contentElement = document.getElementById('content');
    
    const section = document.createElement('section');
    section.innerHTML = `
        <h2>欢迎使用密码工具</h2>
        <p>这是一个强大的密码工具，支持多种密码生成模式。</p>
        <div class="features">
            <h3>主要功能</h3>
            <ul>
                <li>7种密码生成模式</li>
                <li>自定义密码长度</li>
                <li>现代化用户界面</li>
            </ul>
        </div>
        <div class="github-corner">
            <img src="img/github.png" alt="GitHub" class="github-logo">
        </div>
    `;
    
    contentElement.appendChild(section);
}
