export function loadGuideContent() {
    const contentElement = document.getElementById('content');
    
    const section = document.createElement('section');
    section.innerHTML = `
        <h2>使用指南</h2>
        <div class="step">
            <h3>基本使用</h3>
            <ol>
                <li>点击"生成密码"按钮打开密码生成器</li>
                <li>输入密码长度(1-100)</li>
                <li>选择密码生成模式</li>
                <li>点击"生成"按钮获取密码</li>
            </ol>
        </div>
    `;
    
    contentElement.appendChild(section);
}
