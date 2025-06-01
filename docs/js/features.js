export function loadFeaturesContent() {
    const contentElement = document.getElementById('content');
    
    const section = document.createElement('section');
    section.innerHTML = `
        <h2>功能介绍</h2>
        <div class="feature-item">
            <h3>密码生成模式</h3>
            <ul>
                <li>纯数字密码</li>
                <li>纯字母密码</li>
                <li>数字+字母组合</li>
                <li>特殊符号密码</li>
                <li>符号+数字组合</li>
                <li>符号+字母组合</li>
                <li>符号+数字+字母组合</li>
            </ul>
        </div>
    `;
    
    contentElement.appendChild(section);
}
